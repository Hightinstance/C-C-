

  SELECT * FROM course
  
  SELECT * FROM student
  
  -- 12、查询至少有一门课与学号为"01"的同学所学相同的同学的信息
  
   SELECT * FROM student WHERE s_id = '01'
   
   SELECT * FROM course
   
   SELECT * FROM total WHERE t_id IN  (SELECT t_id FROM total WHERE s_id = '01')
   
-- 13、查询和"01"号的同学学习的课程完全相同的其他同学的信息

  (SELECT * FROM student WHERE s_id != '01')a  JOIN (SELECT * FROM score)

  SELECT c_id FROM score WHERE s_id = '01' /* 01 同学学习的课程的分数 */
  
SELECT * FROM student a  JOIN score b WHERE a.s_id = b.s_id 
  
  
  SELECT * FROM student
WHERE s_id IN
(  SELECT s_id FROM (SELECT score.s_id,a.c_id FROM  (SELECT c_id FROM score WHERE s_id='01') a 
                 INNER JOIN  score
                     ON a.c_id=score.c_id) b
                          WHERE s_id<>'01' 
                             GROUP BY s_id HAVING COUNT(c_id)=
                                 (SELECT COUNT(c_id) FROM score WHERE s_id='01'));
     
      
 /* 查询 c_id 课程为 01 的学生编号 */   
 
SELECT * FROM student WHERE s_id 
 SELECT s_id,COUNT(c_id) FROM (
 SELECT score.s_id , a.c_id FROM ( SELECT c_id FROM score WHERE  s_id = '01' ) a INNER JOIN score ON a.c_id = score.c_id WHERE s_id <> '01'
 ) b GROUP BY s_id 
 HAVING COUNT(c_id) = ( SELECT COUNT(*) FROM score WHERE s_id = '01' ) 
 
 
 /* 有多个s_id重复 */
 
 SELECT * FROM score
 
 SELECT * FROM student WHERE s_id IN
 (SELECT s_id FROM 
 ( SELECT score.s_id , a.c_id FROM 
     ( SELECT c_id FROM score WHERE  s_id = '01' ) a INNER JOIN score ON a.c_id = score.c_id WHERE s_id <> '01' ) b 
     GROUP BY s_id )

 SELECT * FROM score WHERE s_id = '01' 
  