-- dimar's solution
select *, case
when x + y <= z or x + z <= y or y + z <= x then 'No'
when x + y > z and x + z > y and y + z > x then 'Yes' end as triangle
from triangle