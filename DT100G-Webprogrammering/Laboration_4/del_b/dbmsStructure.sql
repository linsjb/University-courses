CREATE DATABASE guestbook;
 USE GuestBook;

CREATE TABLE guestbookPosts (
  id  int not null auto_increment,
  username varchar(100),
  postContent tinytext,
  postDate varchar(100),

  CONSTRAINT PK PRIMARY KEY (id)
);
