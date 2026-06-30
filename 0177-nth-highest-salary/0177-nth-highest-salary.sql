CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    RETURN (
        SELECT MAX(salary) FROM ( SELECT salary,
            DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
            FROM Employee
        ) AS t
        WHERE rnk = N
    );
END