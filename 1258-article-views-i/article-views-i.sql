-- dimar's solution
select distinct viewer_id id
from views
where viewer_id = author_id
order by id