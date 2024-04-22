#include<string>;
#include<iostream>;
#include"ActivityBST.h";
using namespace std;
string fill_with_zeros(int num_zeros, const string& input){
int zeros_to_add = num_zeros - input.length();
if (zeros_to_add < 0) zeros_to_add = 0;
return string(zeros_to_add, '0') + input;
}
string number_to_time(int number){
return fill_with_zeros(2, to_string(number/100))+":"+ fill_with_zeros(2,
to_string(number%100));
}

void delete_tree(tree_node *root){
	if(root==nullptr){
		return;
	}
	delete_tree(root->left);
	delete_tree(root->right);

	delete root;

	return;
}
void add_activity(tree_node *&root, int time, const string &activity){
	int hour=time/100;
	int minute=time%100;
	if((23>=hour) &&(0<=hour) &&(59>=minute)&&(minute>=0)){
		tree_node *newNode,	// Pointer to a new node
	              *nodePtr;	// Pointer to traverse the tree

		// Create a new node
		newNode = new tree_node(time,activity);
		newNode->left = newNode->right = nullptr;
		if (!root)// Is the tree empty?
		{
			root = newNode;
			
		}
		else //we have a root, need to find the location for
 		{    //the next item
			nodePtr = root; 
		while (nodePtr) {
			if (time < nodePtr->time) {
				if (nodePtr->left){
					nodePtr = nodePtr->left;
				}
				else {
					nodePtr->left = newNode;
					newNode->parent=nodePtr;
					break;
				}
			}
			else if (time > nodePtr->time) {
				if (nodePtr->right){
					nodePtr = nodePtr->right;
				}
				else {
					nodePtr->right = newNode;
					newNode->parent=nodePtr;
					break;
				}
			}
		}
	}
}
}
void recursive_copy(tree_node*&root, tree_node*&copy_root){
	if (copy_root)
	{
		add_activity(root,copy_root->time,copy_root->activity);
		recursive_copy(root,copy_root->left);		
		recursive_copy(root,copy_root->right);
	}



}

void recursive_print(tree_node*&copy_root){
	if (copy_root)
	{
		
		recursive_print(copy_root->left);
		cout<<copy_root->time<<":	"<<copy_root->activity<<endl;
		recursive_print(copy_root->right);
	}
}


ostream& ActivityBST::recursive_os(ostream& output, const tree_node* root) const{
	if (root == NULL)
		return output;

	recursive_os(output, root->left);
	output<< "["<<number_to_time(root->time)<<"] - "<<root->activity<<endl;
	recursive_os(output, root->right);
	return output;
}


ActivityBST::ActivityBST()
{
	root=nullptr;
}
ActivityBST::ActivityBST( ActivityBST & copy)
{
	tree_node* temp=nullptr;
	recursive_copy(temp,copy.root);
	root=temp;

}

ActivityBST::~ActivityBST()
{
	delete_tree(root);
}
void ActivityBST::add(int time, const string& activity){
	add_activity(root,time,activity);
}
tree_node* ActivityBST::getroot() const
{
	tree_node* a=root;
	return a;

}
  ActivityBST ActivityBST::operator = ( ActivityBST &rhs) 
  {
	  delete_tree(this->root);
	  this->root=nullptr;
	  recursive_copy(this->root,rhs.root);
	  return *this;
  }
   ActivityBST operator + (ActivityBST &lhs, ActivityBST &rhs)
  {
	ActivityBST result(lhs);
    result += rhs;
	result.printtree();
    return result;

  }
   ActivityBST& ActivityBST::operator += ( ActivityBST &rhs)
  { 
	  recursive_copy(root,rhs.root);
	  return *this;
  }

  void ActivityBST::printtree()
  {
	  recursive_print(root);

  }

  ostream& operator<<(ostream& output, const ActivityBST& tree) {
	  return tree.recursive_os(output, tree.getroot());
  }


