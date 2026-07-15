-- dimar's solution
select to_char(trans_date, 'YYYY-MM') as month, country, count(coalesce(country, 'e')) trans_count, count(case when state = 'approved' then state end) approved_count, sum(amount) trans_total_amount, coalesce(sum(case when state = 'approved' then amount end), 0) approved_total_amount
from transactions
group by to_char(trans_date, 'YYYY-MM'), country