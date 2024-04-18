select version(),  current_date, now() from dual;

--  수학함수도 사용할 수 있다.(사칙연산)
select sin(pi() / 4), 1 + 2 * 3 - 4 from dual;

--  mysql(특) 대소문자 구분이 없다.
select VersION(), current_DATE, NOW() from duAL;

-- table 생성: DDL
create table pet(
	name varchar(100),
    owner varchar(20),
    species varchar(20),
    gender char(1),
    birth date,
    death date
);

--  schema 확인
 show tables;
 describe pet;
 desc pet;
 
 -- 테이블 삭제: DDL
 drop table pet;
 show tables;
 
 -- insert: DML(C)
 insert
   into pet
 values ('성탄이', '안대혁', 'dog', 'm', '2019-12-25', null);
 
 -- select: DML(R)
 select * from pet;
 
 -- update: DML(U)
 update pet
    set name='성타니'
  where name='성탄이';
  
-- delete: DML(D)
delete
  from pet
 where name='성타니';

-- load data
load data local infile 'pet.txt' into table pet; 

-- select 연습
-- 문1) bowser의 주인 이름은?
select owner from pet where name = 'bowser'; 

-- 문2) 1998년 이 후에 태어난 아이들의 이름과 출생년도를 출력하세요.
select name, birth
  from pet
 where birth > '1997-12-31';

-- 문제3) order by ~ (asc)
select name, birth from pet order by birth; 

-- 문제4) order by ~ desc
select name, birth from pet order by birth desc;

-- 문제5) null 다루기
select name, birth, death
  from pet
 where death is not null;

select name, birth, death
  from pet
 where death is null;

-- 문제6) like 검색
select name
  from pet
 where name like 'b%';

select name
  from pet
 where name like '%fy';

select name
  from pet
 where name like '%w%';

select name
  from pet
 where name like '____';
 
select name
  from pet
 where name like 'b____';
 
-- 문제7) 집계 함수: count, avg, sum, max, min
select count(*) from pet;
select min(birth), max(birth) from pet;