CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
    
BEGIN
  Declare toSkip int;
    Set toSkip = N-1;
  RETURN (
      # Write your MySQL query statement below.
        select Distinct salary from Employee 
            Order by salary DESC  
            LIMIT toSkip ,1 # Skip N-1 rows and get the next one
  );
END