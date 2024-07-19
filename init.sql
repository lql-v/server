use server;
drop table if exists user_table;
create table if not exists user_table(
    id int primary key auto_increment,
    username varchar(32) unique,
    password varchar(64)
);

insert into user_table (username, password) 
        values ('test1', 'E10ADC3949BA59ABBE56E057F20F883E'),
                ('test2','E35CF7B66449DF565F93C607D5A81D09');
                
select * from user_table;


drop table if exists images_table;
create table if not exists images_table(
    id int primary key auto_increment,
    imgname varchar(128) unique not null,
    imgdata blob 
);