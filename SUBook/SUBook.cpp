#include <iostream>
#include <string>
#include <vector>


#include "SUBook.h"
using namespace std;
User::User()
{
	num_comments=0;
}

User::User(string username)
{
	name=username;
	num_comments=0;
}

 void User::increase_num_comments()
{
	num_comments+=1;
}
 void User::decrease_num_comments()
{
	num_comments+=-1;
}
 int User:: getNumComments()
 {
	 return num_comments;
 }
 vector<Post*> User::getPosts()
 {

	 return Posts;
 }
 string User::getName()
 {
	 return name;
 }

 Post& User::createPost(string content)
 {
	 Post* point= new Post();
	 point->get_value(this,content);
	 Posts.push_back(point);
	 return *point;


 }

 Post::Post()
 {
	user=nullptr;
	content="";
 }

 
 Post::Post(User user1,string text)
 {
	 content=text;
	 user=&user1;

 }
 
 Post::Post(User* user1,string text){
 
	 content=text;
	 user=user1;

 }
 
 void Post::get_value(User*u, string text)
 {
	 user=u;
	 content=text;
 }
 void Post::addComment(string content, User* commenter)
 {
	Comment* point= new Comment();
	point->add_values(commenter,this,content);
	 comments.push_back(point);
 }
 vector<Comment*>Post:: getComments()
 {
	 return comments;
 }
 string Post::getContent()
 {
	 return content;
 }
 User& Post::getUser()
 {
	 return *user;
 }
 Comment::Comment ()
 {
	 user1=nullptr;
	 post1=nullptr;
	 content="";
 }
 
 Comment::Comment(User user,Post post,string text)
 {
	 user1=&user;
	 post1=&post;
	 content=text;
	 user1->increase_num_comments();
 }
 Comment::Comment(User* user,Post* post,string text)
 {
	 user1=user;
	 post1=post;
	 content=text;
 }
 
 string Comment::getContent()
 {
	 return content;
 }
 Post& Comment::getPost()
 {
	 return *post1;
 }
 User& Comment::getUser()
 {
	 return *user1;
 }
 void Comment::add_values(User* user,Post* post,string text)
 {
	 user1=user;
	 post1=post;
	 content=text;
	 user1->increase_num_comments();
 }
 Post::~Post()
 {
	 for(int i=0;i<comments.size();i+=1)
	 {
		 delete comments[i];

	 }
	 comments.clear();
 }
 Comment:: ~Comment()
 {
	 user1->decrease_num_comments();
 }
 User::~User()
{
	for(int i=0;i<Posts.size();i+=1)
	 {
		 Posts[i]->~Post();
		 delete Posts[i];

	 }
	 Posts.clear();

}