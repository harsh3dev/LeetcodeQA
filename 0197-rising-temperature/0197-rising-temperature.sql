select t2.id
from Weather t1 inner join Weather t2
on datediff(t2.recordDate, t1.recordDate) = 1
where t2.temperature > t1.temperature