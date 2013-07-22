#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_node {
	int value;
	struct s_node* left;
	struct s_node* right;
} t_node;

enum parcour_mode{
    PREFIX,
    INFIX,
    SUFFIX
};
enum path_mode{
    ALL,
    INTERN,
    EXTERN
};
t_node* node_create(int value);
void tree_display(t_node* root, enum parcour_mode mode);
int tree_length(t_node* root);
int tree_height(t_node* root);
int tree_LC(t_node* root);
int tree_LC_recurse(t_node* root, int depth, enum path_mode);
int tree_LCE(t_node* root);
int tree_LCI(t_node* root);
float tree_avgdeep(t_node* root);
float tree_avgdeep_I(t_node* root);
float tree_avgdeep_E(t_node* root);
void tree_ASCII_display(t_node* root);

int main ( int argc, char ** argv ){
	t_node* root = node_create(18);
	root->left = node_create(15);
	root->right = node_create(25);
	root->right->right = node_create(30);
	root->right->left = node_create(22);
	root->left->right = node_create(17);
	root->left->left = node_create(13);

	printf("size:%d\n",tree_length(root));
	printf("height:%d\n",tree_height(root));
	printf("LC:%d\n",tree_LC(root));
	printf("LCE:%d\n",tree_LCE(root));
	printf("LCI:%d\n",tree_LCI(root));
	printf("AvgD:%f\n",tree_avgdeep(root));
	printf("AvgDI:%f\n",tree_avgdeep_I(root));
	printf("AvgDE:%f\n",tree_avgdeep_E(root));

	tree_display(root,INFIX);printf("\n");
	exit(0);
}

t_node* node_create(int value){
	t_node * new_node = ( t_node * ) malloc( sizeof ( t_node ) ) ;
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
void tree_display(t_node* root, enum parcour_mode mode){
	if(!root) return;
	if(mode == PREFIX) printf("%d,",root->value);
	if(root->left) tree_display(root->left,mode);
	if(mode == INFIX) printf("%d,",root->value);
	if(root->right) tree_display(root->right,mode);
	if(mode == SUFFIX) printf("%d,",root->value);
}
int tree_length(t_node* root){
	return (root) ? (1 + (tree_length(root->left) + tree_length(root->right))) : 0;
}
int tree_internal_length(t_node* root){
	return (root) ? ((root->left != NULL || root->right != NULL) ? (1 + (tree_internal_length(root->left) + tree_internal_length(root->right))) : (tree_internal_length(root->left) + tree_internal_length(root->right)) ) : 0;
}
int tree_external_length(t_node* root){
	return (root) ? ((root->left == NULL && root->right == NULL) ? (1 + (tree_external_length(root->left) + tree_external_length(root->right))) : (tree_external_length(root->left) + tree_external_length(root->right)) ) : 0;
}
int tree_height(t_node* root){
	if(root && (root->left || root->right)){
		int heightL = tree_height(root->left);
		int heightR = tree_height(root->right);
		return 1 + (((heightL >= heightR)) ? heightL : heightR);
	}
	return 0;
}
int tree_LC(t_node* root){
	return tree_LC_recurse(root, -1, ALL);
}
int tree_LCE(t_node* root){
	return tree_LC_recurse(root, -1, EXTERN);
}
int tree_LCI(t_node* root){
	return tree_LC_recurse(root, -1, INTERN);
}
int tree_LC_recurse(t_node* root, int depth, enum path_mode mode){
	depth++;
	if(root && mode == ALL){
		return (depth+tree_LC_recurse(root->left,depth,mode) + tree_LC_recurse(root->right,depth,mode));
	}
	if(root && mode == EXTERN){
		if(root->left == NULL && root->right == NULL) return (depth+tree_LC_recurse(root->left,depth,mode) + tree_LC_recurse(root->right,depth,mode));
		else return (tree_LC_recurse(root->left,depth,mode) + tree_LC_recurse(root->right,depth,mode));
	}
	if(root && mode == INTERN){
		if(root->left != NULL || root->right != NULL) return (depth+tree_LC_recurse(root->left,depth,mode) + tree_LC_recurse(root->right,depth,mode));
		else return (tree_LC_recurse(root->left,depth,mode) + tree_LC_recurse(root->right,depth,mode));
	}
	return 0;
}
float tree_avgdeep(t_node* root){
	return ((float)tree_LC(root)/(float)tree_length(root));
}
float tree_avgdeep_I(t_node* root){
	return ((float)tree_LCI(root)/(float)tree_internal_length(root));
}
float tree_avgdeep_E(t_node* root){
	return ((float)tree_LCE(root)/(float)tree_external_length(root));
}
void tree_ASCII_display(t_node* root){

}
