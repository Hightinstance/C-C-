 
 SELECT * FROM  course
  
 SELECT * FROM  score
  
 SELECT * FROM  student , score WHERE studetn.s

 SELECT * FROM  teacher
 
 SELECT SUM(s.score) AS sumscore,s.s_id FROM
    ( SELECT * FROM  student a  , score b WHERE a.s_id =  b.s_id) s 
       GROUP BY s.s_id
       
       
 SELECT s.score FROM ( SELECT * FROM  student a  JOIN IN score b ON a.s_id =  b.s_id ) s
  
 SELECT c.s_id,SUM(c.score) FROM ( SELECT a.*,b.c_id,b.score FROM  student a  INNER JOIN  score b ON a.s_id =  b.s_id ) c
 GROUP BY c.s_id;
 
 -- 1、查询"01"课程比"02"课程成绩高的学生的信息及课程分数
 
 -- 查询学生信息和分数 连表查询

 SELECT * FROM student s1 JOIN  score s2 ON  s1.s_id = s2.s_id
  
  -- 查询 01 课程大于02 课程的 s_id
  -- 查询 01 课程
  -- 查询 02 课程
  -- 查询 01 > 02 课程
 SELECT * FROM score  
 
 SELECT * FROM score WHERE c_id ='01';
 
 SELECT * FROM score WHERE c_id = '02';
 
 
  SELECT * FROM  
  ( ( SELECT * FROM score WHERE c_id ='01' ) a 
      JOIN  ( SELECT * FROM score WHERE c_id = '02') b 
     ON a.s_id = b.s_id) c WHERE a.socre > b.score 
     
     
  SELECT * FROM student s1 JOIN  score s2 ON  s1.s_id = s2.s_id   (SELECT a.s_id FROM  ( SELECT * FROM score WHERE c_id ='01' ) a 
      JOIN  ( SELECT * FROM score WHERE c_id = '02') b 
     ON a.s_id = b.s_id WHERE a.score > b.score ) 
 

 
 
 