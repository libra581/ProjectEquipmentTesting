--Создание таблиц базы данных BD_MAIN
--PosgreSQL 10

CREATE TABLE Equipment 
(
	IdChild INTEGER PRIMARY KEY,
	Name VARCHAR(20) UNIQUE NOT NULL,
	Weight SMALLINT CHECK(Weight > 0),
	IdParent INTEGER REFERENCES Equipment(IdChild)
);

CREATE TABLE EMode 
(
	Code INTEGER PRIMARY KEY,
	Name VARCHAR(20) UNIQUE NOT NULL,
	Note VARCHAR(300)
);

CREATE TABLE Testing 
(
	Id SERIAL PRIMARY KEY,
	Name VARCHAR(20) UNIQUE NOT NULL,
	Note VARCHAR(300)
);

CREATE TABLE MoscowTime 
(
	Id SERIAL PRIMARY KEY,
	FourYeares INTEGER NOT NULL,
	Time TIME NOT NULL,
	CurrentDay INTEGER NOT NULL,
	CHECK(FourYeares > 0 AND CurrentDay > 0)
);

CREATE TABLE Request 
(
	Id SERIAL PRIMARY KEY,
	Date DATE NOT NULL,
	Time TIME NOT NULL,
	IdEquip INTEGER REFERENCES Equipment(IdChild),
	CodeMode INTEGER REFERENCES EMode(Code),
	IdTesting INTEGER NULL REFERENCES Testing(Id),
	IdMT INTEGER REFERENCES MoscowTime(Id)
);

CREATE TABLE TestingData 
(
	Code SERIAL PRIMARY KEY,
	AddressData INTEGER NOT NULL,
	NumberProgram INTEGER DEFAULT 1,
	AmountDataWords INTEGER NOT NULL,
	State INTEGER NOT NULL,
	Reserve BYTEA
);

CREATE TABLE OneTimeCommands 
(
	Code SERIAL PRIMARY KEY,
	Comp1 BOOLEAN DEFAULT TRUE,
	Comp2 BOOLEAN DEFAULT FALSE,
	EnableParachute BOOLEAN DEFAULT TRUE,
	PS1 BOOLEAN DEFAULT TRUE,
	PS2 BOOLEAN DEFAULT FALSE,
	SpecInfo INTEGER
);

CREATE TABLE TMI 
(
	Id SERIAL PRIMARY KEY,
	ContentMemoryCells Bigint NOT NULL,
	StateEquipment Bigint NOT NULL,
	LoadCurrents Bigint NOT NULL,
	SpecInfo Integer
);

CREATE TABLE Session 
(
	Id CHAR(6) PRIMARY KEY,
	MassiveModes INTEGER NOT NULL,
	CodeCommands INTEGER REFERENCES OneTimeCommands(Code),
	CodeTestData INTEGER REFERENCES TestingData(Code)
);

CREATE TABLE FAnalyze 
(
	IdRequest INTEGER REFERENCES Request(Id),
	IdSession CHAR(6) REFERENCES Session(Id),
	PRIMARY KEY(IdRequest, IdSession),
	CodeExecute INTEGER NOT NULL,
	FileDeviations BYTEA,
	IdTMI INTEGER NULL REFERENCES TMI(Id) ON DELETE SET NULL
);
