#include <iostream>
#include <string>
#include <vector>


using namespace std;
#ifndef _SUBOOK_H
#define _SUBOOK_H

class User;
class Post;
class Comment;

class User{
    public:
		User();
		User(string username);
		~User();
		Post& createPost(string content);
		vector<Post*> getPosts();
		int getNumComments();
		string getName();
		void increase_num_comments();
		void decrease_num_comments();
    private:
		string name;
		vector<Post*>Posts;
		int num_comments;
		


};
class Post{
	public:
		Post();
		Post(User user1,string text);
		Post(User* user1,string text);
		~Post();
		void addComment(string content, User* commenter);
		vector<Comment*> getComments();
		User& getUser();
		string getContent();
		void get_value(User* u,string text);

	
	private:
		User* user;
		string content;
		vector<Comment*>comments;

};
class Comment{
	public:
		Comment();
		Comment(User user,Post post,string text);
		Comment(User* user,Post* post,string text);
		~Comment();
		User& getUser();
		string getContent();
		Post& getPost();
		void Comment::add_values(User* user,Post* post,string text);


	private:
		User* user1;
		string content;
		Post* post1;

};








#endif