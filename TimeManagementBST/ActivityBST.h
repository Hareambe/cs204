#ifndef _ACTIVITYBST_H
#define _ACTIVITYBST_H

#include<string>;
#include<iostream>
using namespace std;


struct tree_node {
int time;
string activity;
tree_node *right;
tree_node *left;
tree_node *parent;
tree_node(int t, const string &a) : time(t), activity(a),
right(nullptr), left(nullptr),
parent(nullptr) {}
};

class ActivityBST
{
    public:
		ActivityBST();
		~ActivityBST();
		ActivityBST::ActivityBST(ActivityBST& copy);
		void add(int time, const string& activity);
		ActivityBST operator=( ActivityBST &rhs);
		ActivityBST& operator +=(ActivityBST& rhs);
		tree_node* getroot() const;
		void printtree();
		ostream& recursive_os(ostream& output, const tree_node* root) const;

    private:
		tree_node* root;
		


};
		void delete_tree();
		void add_activity();
		void recursive_copy();
		void recursive_print(tree_node*&copy_root);
		ActivityBST operator + (ActivityBST &lhs,ActivityBST & rhs);
		ostream& operator<<(ostream&, const ActivityBST&);

#endif
		