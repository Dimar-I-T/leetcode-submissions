-- dimar's solution
with gabung as (
    select e.name ename, d.name dn, e.salary es
    from employee e
    join department d on
        d.id = e.departmentId
), ranking as (
    select ename, es, dn, dense_rank() over(partition by dn order by es desc) r
    from gabung
)

select dn department, ename employee, ranking.es salary
from ranking
where r = 1