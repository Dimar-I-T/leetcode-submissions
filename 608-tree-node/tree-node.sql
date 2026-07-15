-- dimar's solution
with ri as (
    select p_id,
     case when
        p_id is not null and p_id not in (select id
                                          from tree
                                          where p_id is null)
        then 'Inner'
     end as type
    from tree
), gabung as (
    select ri.p_id rid, type
    from ri
    union 
    select id as rid, null as type
    from tree
    where id not in (select distinct p_id from ri where p_id is not null)
), joinR as (
    select rid, type, t.id tid
    from gabung
    left join tree t on
        t.p_id is null and gabung.type is null
), jadi as (
    select distinct case when
        rid is null and type is null then tid
        else rid end as id,
        case when
            rid is null and type is null then 'Root'
            when rid is not null and type is null and rid != tid then 'Leaf'
            when type = 'Inner' and tid is null then 'Inner'
        end as type
    from joinR
)

select * from jadi where type is not null