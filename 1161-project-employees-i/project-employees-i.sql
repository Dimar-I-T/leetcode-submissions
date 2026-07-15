-- dimar's solution
with satu as (
    select p.project_id, p.employee_id, experience_years
    from project p
    join employee e on
        p.employee_id = e.employee_id
)

select project_id, round(avg(experience_years), 2) average_years
from satu
group by project_id