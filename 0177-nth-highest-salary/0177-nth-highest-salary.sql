CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set n = n-1;
  RETURN (
      SELECT distinct Salary FROM Employee 
ORDER BY Salary DESC LIMIT n,1
  );
END