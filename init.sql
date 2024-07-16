creata table if not exist user_table(
    id int primary key auto_increment,
    name varchar(20) unique,
    password varchar(20)
);