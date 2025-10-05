# Write your MySQL query statement below
select e1.name , e2.bonus 
from 
employee as e1
left join bonus as e2
on e1.empId=e2.empId
where e2.bonus<1000 || e2.bonus is null
