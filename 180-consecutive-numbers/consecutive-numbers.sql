-- dimar's solution
with n1n2 as (
    select row_number() over() r, l1.num num1, l2.num num2
    from logs l1
    left join logs l2 on
        l1.id = l2.id - 1
), gabung as (
    select nn1.num1, nn1.num2, nn2.num1 num3, nn2.num2 num4
    from n1n2 nn1
    inner join n1n2 nn2 on
        nn1.r = nn2.r - 1
), pilter as (
    select num1
    from gabung
    where num1 = num2 and num1 = num3 and 
          num1 = num4 and num2 = num3 and
          num2 = num4 and num3 = num4
)

select distinct num1 ConsecutiveNums
from pilter