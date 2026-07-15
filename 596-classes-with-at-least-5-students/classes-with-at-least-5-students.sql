-- dimar's solution
select class
from courses
group by class
having count(*) >= 5
order by count(*) desc