create database Quanlycauhinh;
use Quanlycauhinh;

create table Device(
	device_id int primary key identity(1,1),
	hostname varchar(100),
	ip_address varchar(50),
	device_type varchar(50),
	manufacturer varchar(100),
	model varchar(100),
	serial_number varchar(50),
	os_version varchar(50),
	cpu varchar(100),
	ram varchar(50),
	storage varchar(50),
	purchase_date date,
	warranty_expiry date,
	vendor varchar(100),
	[location] varchar(100),
	[status] varchar(20) check ([status] IN (N'active', N'inactive')),
	created_at varchar(50)
);

create table Maintenance(
	maintenance_id int primary key identity(1,1),
	device_id int,
	FOREIGN KEY (device_id) REFERENCES Device(device_id),
	maintenance_date date,
	performed_by varchar(100),
	[description] text,
	cost decimal
);

create table [User](
	[user_id] int primary key identity(1,1),
	username varchar(50),
	[password] varchar(255),
	[role] varchar(20) check ([role] IN (N'Admin', N'User', N'Viewer'))
);
create table Software(
	software_id int primary key identity(1,1),
	device_id int foreign key references Device(device_id),
	[name] varchar(100),
	[version] varchar(50),
	install_date date,
	license_key varchar(100)
);

create table [Configuration](
	config_id int primary key identity(1,1),
	device_id int foreign key references Device(device_id),
	[version] varchar(50),
	config_data text,
	created_by int foreign key references [User]([user_id]),
	created_at timestamp
);

create table Interface(
	interface_id int primary key identity(1,1),
	device_id int foreign key references Device(device_id),
	[name] varchar(50),
	mac_address varchar(50),
	ip_address varchar(50),
	subnet_mask varchar(50),
	[status] varchar(20) check ([status] IN (N'up', N'down'))
);

create table [Connection](
	connection_id int primary key identity(1,1),
	device1_id int foreign key references Device(device_id),
	interface1_id int foreign key references Interface(interface_id),
	device2_id int foreign key references Device(device_id),
	interface2_id int foreign key references Interface(interface_id),
	[status] varchar(20) check ([status] IN (N'active', N'inactive'))
);

insert into [User] ([username], [password], [role])
values
('thai', 'thai123', 'Admin'),
('thao', 'thao123', 'User'),
('trang', 'trang123', 'Viewer');

insert into Device (hostname, ip_address, device_type, manufacturer, model, serial_number, os_version, cpu, ram, storage, purchase_date, warranty_expiry, vendor, [location], [status], created_at)
values
('Router1', '192.168.1.1', 'Router', 'Cisco', 'XR500', 'SN123456789', 'IOS-XE', 'Intel', '8GB', '256GB', '2023-01-01', '2026-01-01', 'Cisco', 'Data Center', 'active', '2023-01-01'),
('Switch1', '192.168.1.2', 'Switch', 'Juniper', 'EX4300', 'SN987654321', 'Junos', 'AMD', '4GB', '128GB', '2022-06-01', '2025-06-01', 'Juniper', 'Main Office', 'inactive', '2022-06-01');

insert into Maintenance (device_id, maintenance_date, performed_by, [description], cost)
values
(1, '2023-02-01', 'admin', 'Replaced faulty port', 500),
(2, '2023-07-01', 'user', 'Firmware update', 200);

insert into Software (device_id, [name], [version], install_date, license_key)
values
(1, 'Cisco IOS', 'XE 16.9', '2023-01-01', 'LIC123456789'),
(2, 'Juniper Junos', '18.3R2', '2022-06-01', 'LIC987654321');

insert into [Configuration] (device_id, [version], config_data, created_by)
values
(1, 'v1.0', 'interface GigabitEthernet1/0/1 description link to office', 1),
(2, 'v1.1', 'interface Ethernet0 description link to data center', 2);

insert into Interface (device_id, [name], mac_address, ip_address, subnet_mask, [status])
values
(1, 'GigabitEthernet1/0/1', '00:1D:A2:3F:5B:6C', '192.168.1.10', '255.255.255.0', 'up'),
(2, 'Ethernet0', '00:1D:A2:3F:5B:6D', '192.168.1.20', '255.255.255.0', 'down');

insert into [Connection] (device1_id, interface1_id, device2_id, interface2_id, [status])
values
(1, 1, 2, 2, 'active'),
(2, 2, 1, 1, 'inactive');
