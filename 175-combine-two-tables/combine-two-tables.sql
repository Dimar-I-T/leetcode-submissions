-- dimar's solution
select firstName, lastName, a.city, a.state
from person p
left join address a
on p.personid = a.personid