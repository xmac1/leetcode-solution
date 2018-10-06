-- 使用外联结保证没有数据的联结项目为null
SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person  LEFT OUTER JOIN Address ON Person.PersonId = Address.PersonId;