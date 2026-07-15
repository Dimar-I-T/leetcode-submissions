select case
when "SecondHighestSalary" = -1 then null
else "SecondHighestSalary" end
as "SecondHighestSalary" from
(select -1 as "SecondHighestSalary"
union all
select -1 as "SecondHighestSalary"
union all
select distinct salary as "SecondHighestSalary"
from employee
order by "SecondHighestSalary" desc
offset 1
limit 1) s