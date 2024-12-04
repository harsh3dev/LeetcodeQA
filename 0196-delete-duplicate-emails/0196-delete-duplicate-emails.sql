# Write your MySQL query statement below
with acc_id as (
    select min(id) as min_id
    from Person
    group by email
)
delete from Person
where id not in (
    select min_id from acc_id
)