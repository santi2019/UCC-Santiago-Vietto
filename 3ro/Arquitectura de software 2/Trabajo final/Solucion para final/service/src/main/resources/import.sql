-- You can use this file to load seed data into the database using SQL statements
insert into Location(Name) values ('Mendoza');
insert into Location(Name) values ('Jujuy');
insert into Location(Name) values ('Cordoba');
insert into Location(Name) values ('Corrientes');
insert into Location(Name) values ('Salta');


insert into Sensor (Location_ID, Status) values (1, 1);
insert into Sensor (Location_ID, Status) values (2, 1);
insert into Sensor (Location_ID, Status) values (2, 0);
insert into Sensor (Location_ID, Status) values (2, 1);
insert into Sensor (Location_ID, Status) values (3, 1);
insert into Sensor (Location_ID, Status) values (3, 0);
insert into Sensor (Location_ID, Status) values (4, 1);
insert into Sensor (Location_ID, Status) values (4, 1);
insert into Sensor (Location_ID, Status) values (4, 1);
insert into Sensor (Location_ID, Status) values (5, 1);

insert into Register (Temperature, Pressure, Wind, Timestamp, Sensor_id) values (10, 1.102, 8, '2021-12-03 10:20:21', 1);
insert into Register (Temperature, Pressure, Wind, Timestamp, Sensor_id) values (25, 1.102, 5, '2021-12-03 10:20:13', 2);
insert into Register (Temperature, Pressure, Wind, Timestamp, Sensor_id) values (10, 1.102, 8, '2021-12-03 10:20:43', 1);
insert into Register (Temperature, Pressure, Wind, Timestamp, Sensor_id) values (10, 1.102, 9, '2021-11-07 10:20:43', 1);
insert into Register (Temperature, Pressure, Wind, Timestamp, Sensor_id) values (10, 1.12,  9, '2021-11-07 10:20:43', 1);
insert into Register (Temperature, Pressure, Wind, Timestamp, Sensor_id) values (11, 2.542, 9, '2021-11-07 10:21:43', 1);
insert into Register (Temperature, Pressure, Wind, Timestamp, Sensor_id) values (12, 1.102, 10,'2021-11-07 10:22:43', 2);
insert into Register (Temperature, Pressure, Wind, Timestamp, Sensor_id) values (30, 1.102, 0, '2021-12-03 10:20:10', 2);