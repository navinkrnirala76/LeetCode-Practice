# Write your MySQL query statement below


SELECT
    D.name  Department ,
    E.name Employee,
    E.Salary
FROM
    Employee E
LEFT JOIN
    Department D ON E.departmentId = D.id
WHERE
    (

        SELECT
            COUNT( DISTINCT E1.Salary) Counted
        FROM
            Employee E1
        WHERE
            E1.departmentId = E.departmentId
        AND
            E1.Salary > E.Salary

    ) < 3
