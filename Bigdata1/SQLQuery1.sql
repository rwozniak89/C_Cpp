select tt1.maks, tt2.kraj from
(
select  t1.year, max(t1.indicator) as maks, 1 as kraj
FROM [atest1].[dbo].[tabelapkb] as t1
group by t1.year
) as tt1
left outer join
(select  t1.year, t1.indicator as maks, country as kraj
FROM [atest1].[dbo].[tabelapkb] as t1
) as tt2 on tt1.maks = tt2.maks
order by 1


select tt1.country,tt1.max_i,t2.year from
(
select t1.country,max(t1.indicator) as max_i from [tabelapkb] as t1
group by t1.country
) as tt1
left join [tabelapkb] as t2 on tt1.country=t2.country and tt1.max_i=t2.indicator


select t1.country,max(t1.indicator) as max_i from [tabelapkb] as t1
group by t1.country

select distinct t1.country, max(t1.indicator) over (Partition by t1.year) as maksik
from [atest1].[dbo].[tabelapkb] as t1
group by t1.country
order by 2 desc


select  t1.country, t1.year, max(t1.indicator) as maks
FROM [atest1].[dbo].[tabelapkb] as t1
group by t1.country, t1.year
order by 3 desc

