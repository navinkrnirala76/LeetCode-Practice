# Write your MySQL query statement below
SELECT D.name AS Department, E.name AS Employee,E.salary AS Salary from Employee E,Department D
where D.id=E.departmentId and E.salary=(SELECT max(salary) from Employee E where E.departmentId=D.id);
