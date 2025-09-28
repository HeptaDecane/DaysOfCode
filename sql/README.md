# SQL
Structured Query Language (SQL) is the standard language used to interact with relational databases. 
- It allows users to store, retrieve, update and manage data efficiently through simple commands. 
- Mainly works with Relational Databases i.e. data is stored in the form of tables.


## How Does SQL Work?
1. **Input**: The user submits a query (e.g., SELECT, INSERT, UPDATE, DELETE) via an application or interface.
2. **Parsing**: The query processor breaks the query into parts (tokens) and checks for syntax and schema correctness.
3. **Optimization**: The optimizer finds the most efficient way to run the query using indexes, statistics and available resources.
4. **Execution**: The execution engine runs the query using the chosen plan, accessing or modifying the database as needed.
5. **Output**: Results are returned to the user, either data (for SELECT) or a success message (for other operations).


## Key Components of a SQL System

### Databases
A database is a structured collection of data. It organizes data into **tables**, which are like spreadsheets with rows (records) and columns (fields).
```sql
CREATE DATABASE COMPANY_DB;
```

### Tables
Tables store data and enforce rules and relationships among its columns for data integrity. Each table has a unique name and consists of:
- **Columns**: Define the type of data (e.g., integer, text, date) and constraints (e.g., NOT NULL, UNIQUE).
- **Rows**: Each row represents a single record in the table.
```sql
CREATE TABLE Employees (
    EmployeeId INT PRIMARY KEY,
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL,
    BirthDate DATE,
    HireDate DATE,
    Email NVARCHAR(100) UNIQUE,
    IsActive BIT DEFAULT 1
);
```
  
### Indexes
Indexes speed up queries by allowing the database to quickly locate data without scanning the entire table. They are created on one or more columns of a table and work like a book's index, pointing to the location of data without scanning the entire table.
- **Clustered Index**: 
  - Sorts and stores the data rows in the table based on the index key.
  - Each table can have only **one clustered index** (since data rows themselves can be stored in only one order).
  - By default, **primary key** creates a clustered index if none exists.
    ```sql
    CREATE CLUSTERED INDEX IX_Employee_Id
    ON Employees(EmployeeId);
    ```
- **Non-Clustered Index**:
  - Creates a **separate structure** from the data rows that points to the location of the data.
  - Stores the key values and a pointer (row locator) to the actual data.
  - A table can have **multiple non-clustered indexes**.
    ```sql
    CREATE NONCLUSTERED INDEX IX_Employee_LastName
    ON Employees(LastName);
    ```
- **Unique Index**: 
  - Ensures that no two rows have the same value in the indexed column(s).
  - Can be clustered or non-clustered.
  - Automatically created with **PRIMARY KEY** and **UNIQUE** constraints.
    ```sql
    CREATE UNIQUE INDEX IX_Employee_Email
    ON Employees(Email);
    ```
- **Composite Index**:
  - An index on multiple columns.
  - Useful for queries that filter or sort on multiple columns.
    ```sql
    CREATE NONCLUSTERED INDEX IX_Employee_Name
    ON Employees(LastName, FirstName);
    ```
- **Filtered Index**:
  -  A non-clustered index that includes a WHERE clause to index a subset of rows in a table (e.g., active records).
  - Improves performance and reduces storage for queries that target specific rows.
    ```sql
    CREATE NONCLUSTERED INDEX IX_Active_Employees
    ON Employees(LastName)
    WHERE IsActive = 1;
    ```
- **Covering Index**:
  - A non-clustered index that includes all the columns needed for a specific query, allowing the query to be satisfied entirely from the index without accessing the table.
  - You can use the **INCLUDE** clause to add non-key columns. Improves performance for read-heavy operations.
    ```sql
    CREATE NONCLUSTERED INDEX IX_Employee_Covering
    ON Employees(LastName)
    INCLUDE (FirstName, Email);
    ```
- **Columnstore Index**:
  - Stores data in a **columnar format** instead of row-based, optimizing for read-heavy analytical queries.
  - Can be clustered or non-clustered.
  - Improves performance for large datasets and data warehousing scenarios.
    ```sql  
    CREATE CLUSTERED COLUMNSTORE INDEX IX_Employee_Columnstore
    ON Employees(LastName, FirstName, HireDate);
    ```
- **XML Index**:
  - Used to index XML data stored in XML columns.
  - Improves performance for queries that extract or search XML data.
  - Types: Primary XML Index, Secondary XML Index (PATH, VALUE, PROPERTY).
    ```sql
    CREATE PRIMARY XML INDEX IX_Employee_XML
    ON Employees(XmlColumn);
    ```
- **Spatial Index**:
  - Used to index spatial data types (e.g., geometry, geography).
  - Improves performance for spatial queries (e.g., location-based searches).
    ```sql
    CREATE SPATIAL INDEX IX_Employee_Location
    ON Employees(LocationColumn);
    ```
- **Full-Text Index**:
  - Used for full-text search capabilities on character-based columns.
  - Allows for complex search queries, including phrases and proximity searches.
    ```sql
    CREATE FULLTEXT INDEX ON Employees(FirstName, LastName)
    KEY INDEX PK_EmployeeId;
    ```

### Views 
Views are virtual tables that present data from one or more tables. They do not store data themselves but provide a way to simplify complex queries, enhance security by restricting access to specific columns or rows, and present data in a specific format.
```sql
CREATE VIEW ActiveEmployees AS
SELECT EmployeeId, FirstName, LastName, Email
FROM Employees
WHERE IsActive = 1;
```

### Joins
Joins combine rows from two or more tables based on a related column between them. They are essential for querying relational databases across related datasets. 
- **INNER JOIN**: Returns rows with matching values in both tables.
- **LEFT JOIN (or LEFT OUTER JOIN)**: Returns all rows from the left table and matched rows from the right table; NULLs for non-matches.
- **RIGHT JOIN (or RIGHT OUTER JOIN)**: Returns all rows from the right table and matched rows from the left table; NULLs for non-matches.
- **FULL JOIN (or FULL OUTER JOIN)**: Returns rows when there is a match in one of the tables; NULLs for non-matches on either side.
- **CROSS JOIN**: Returns the Cartesian product of both tables (all combinations of rows).
- **SELF JOIN**: Joins a table to itself to compare rows within the same table.

### Stored Procedures
Stored procedures are precompiled SQL code that can be executed as a single unit. They can accept parameters, contain control-of-flow statements, and help encapsulate business logic within the database. Stored procedures improve performance by reducing the amount of information sent over the network and can enhance security by restricting direct access to underlying tables.
```sql
CREATE PROCEDURE GetEmployeeById
    @EmployeeId INT
AS
BEGIN
    SELECT EmployeeId, FirstName, LastName, Email
    FROM Employees
    WHERE EmployeeId = @EmployeeId;
END;

-- execute the stored procedure
EXEC GetEmployeeById @EmployeeId = 1;
```

### Functions
Functions are similar to stored procedures but are designed to return a single value or a table. They can be used in SQL statements wherever expressions are allowed. Functions can be scalar (returning a single value) or table-valued (returning a table).
```sql
CREATE FUNCTION GetFullName(@FirstName NVARCHAR(50), @LastName NVARCHAR(50))
RETURNS NVARCHAR(101)
AS
BEGIN
    RETURN @FirstName + ' ' + @LastName;
END;

-- use the function in a query
SELECT dbo.GetFullName(FirstName, LastName) AS FullName
FROM Employees;
```

### Triggers
Triggers are special types of stored procedures that automatically execute in response to certain events on a table or view, such as INSERT, UPDATE, or DELETE operations. They are used to enforce business rules, maintain audit trails, and ensure data integrity.
```sql
-- Example of a DML Trigger (AFTER INSERT) --
CREATE TRIGGER trg_AfterInsertEmployee
ON Employees
AFTER INSERT
AS
BEGIN
    -- Log the new employee information into an audit table
    INSERT INTO EmployeeAudit (EmployeeId, ActionType, ActionDate)
    SELECT EmployeeId, 'INSERT', GETDATE()
    FROM INSERTED;
END;
```

### Transactions
Transactions are sequences of one or more SQL operations treated as a single unit of work. They ensure data integrity and consistency by following the ACID properties (Atomicity, Consistency, Isolation, Durability). Transactions can be committed to save changes or rolled back to undo changes in case of errors.
```sql
BEGIN TRANSACTION;
-- SQL operations (e.g., INSERT, UPDATE, DELETE)
IF @@ERROR <> 0
BEGIN
    ROLLBACK TRANSACTION; -- Undo changes if an error occurs
    RETURN;
END
COMMIT TRANSACTION; -- Save changes if all operations succeed
```


## Common SQL Commands
SQL commands are fundamental building blocks used to perform given operations on database. The operations include queries of data. creating a table, adding data to tables, dropping the table, modifying the table and set permission for users.  
SQL Commands are mainly categorized into five categories: 

### 1. Data Definition Language (DDL)
DDL commands are used to define and manage database structures such as tables, indexes, and schemas.
- **CREATE**: Creates a new table, view, or other database object.
- **ALTER**: Modifies an existing database object, such as adding a column to a table.
- **DROP**: Deletes a table, view, or other database object.
- **TRUNCATE**: Removes all records from a table, but keeps the table structure intact.

### 2. Data Manipulation Language (DML)
DML commands are used to manipulate data within existing database objects.
- **INSERT**: Adds new records to a table.
- **UPDATE**: Modifies existing records in a table.
- **DELETE**: Removes records from a table.

### 3. Data Query Language (DQL)
DQL commands are used to query and retrieve data from the database.
- **SELECT**: Retrieves data from one or more tables.
- **WHERE**: Filters records based on specified conditions.
- **JOIN**: Combines rows from two or more tables based on a related column.
- **GROUP BY**: Groups rows that have the same values in specified columns into summary rows.
- **HAVING**: Filters groups based on a specified condition.

### 4. Transaction Control Language (TCL)
TCL commands manage transactions in relational databases, ensuring data integrity and consistency. These commands are used to commit changes or roll back operations in case of errors.
- **COMMIT**: Saves all changes made during the current transaction to the database.
- **ROLLBACK**: Undoes all changes made during the current transaction, reverting the database to its previous state.
- **SAVE**: Sets a point within a transaction to which changes can be rolled back, allowing partial rollbacks

```sql
BEGIN TRANSACTION;
-- Some SQL statements (e.g., INSERT, UPDATE, DELETE)
-- These changes are part of the transaction

SAVE TRANSACTION SP1;
-- More SQL statements 
-- These changes are also part of the transaction

SAVE TRANSACTION SP2;
-- Further SQL statements
-- These changes are also part of the transaction

ROLLBACK TRANSACTION SP1;
-- This undoes ALL changes made after SP1 savepoint
-- Changes made after SP1 (including SP2 savepoint) are rolled back
-- Changes made BEFORE SP1 are still pending in the transaction

COMMIT TRANSACTION;
-- This commits all remaining changes (only those made before SP1)
```

### 5. Data Control Language (DCL)
DCL commands are used to control access to data within the database.
- **GRANT**: Assigns new privileges to a user account, allowing access to specific database objects, actions or functions.
    ```sql
    GRANT SELECT, INSERT ON employees TO user1;
    ```

- **REVOKE**: Removes previously granted privileges from a user account, taking away their access to certain database objects or actions.
    ```sql
    REVOKE DELETE ON employees FROM user1;
    ```


## [SQL Data Types](https://learn.microsoft.com/en-us/sql/t-sql/data-types/data-types-transact-sql)
In SQL, each column must be assigned a data type that defines the kind of data it can store, such as integers, dates, text, or binary values. Choosing the correct data type is crucial for data integrity, query performance and efficient indexing.  

SQL data types are broadly categorized into several groups:  
**1. Numeric Data Types**  
- `BIT`: Stores 0, 1, or NULL (1 bit).
- `TINYINT`: 0 to 255 (1 byte).
- `SMALLINT`: -32,768 to 32,767 (2 bytes).
- `INT`: -2,147,483,648 to 2,147,483,647 (4 bytes).
- `BIGINT`: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (8 bytes).
- `DECIMAL`/`NUMERIC` (p, s): Fixed precision and scale (e.g., `DECIMAL(18,2)` for 18 digits, 2 after decimal).
- `SMALLMONEY`: -214,748.3648 to 214,748.3647 (4 bytes).
- `MONEY`: -922,337,203,685,477.5808 to 922,337,203,685,477.5807 (8 bytes).
- `FLOAT(n)`: Floating point number with n bits of precision (4 or 8 bytes).
- `REAL`: Single-precision floating-point (4 bytes).  


**2. Character and String Data Types**
- `CHAR(n)`: Fixed-length string, up to 8,000 characters (n bytes).
- `NCHAR(n)`: Fixed-length Unicode string, up to 4,000 characters (2n bytes).
- `VARCHAR(n)`: Variable-length string, up to 8,000 characters (actual length + 2 bytes).
- `VARCHAR(MAX)`: Variable-length string, up to 2^31-1 bytes (~2GB).
- `NVARCHAR(n)`: Variable-length Unicode string, up to 4,000 characters (actual length * 2 + 2 bytes).
- `NVARCHAR(MAX)`: Variable-length Unicode string, up to 2^31-1 bytes (~2GB).

**3. Date and Time Data Types**
- `DATE`: Stores date only (YYYY-MM-DD, 3 bytes, 0001-01-01 to 9999-12-31).
- `TIME`: Stores time only (hh:mm:ss[.nnnnnnn], 3-5 bytes, up to 7 decimal places for seconds).
- `DATETIME`: Stores date and time (YYYY-MM-DD hh:mm:ss[.nnn], 8 bytes, 1753-01-01 to 9999-12-31, 3.33ms precision).
- `DATETIME2`: Stores date and time with extended range and precision (YYYY-MM-DD hh:mm:ss[.nnnnnnn], 6-8 bytes, 100ns precision).
- `DATETIMEOFFSET`: Stores date, time, and time zone (YYYY-MM-DD hh:mm:ss[.nnnnnnn] [+|-]hh:mm, 8-10 bytes).
- `SMALLDATETIME`: Stores smaller range date and time (YYYY-MM-DD hh:mm:ss, 4 bytes, 1900-01-01 to 2079-06-06, 1-minute precision).

**4. Binary Data Types**
- `BINARY(n)`: Fixed-length binary data, up to 8,000 bytes.
- `VARBINARY(n)`: Variable-length binary data, up to 8,000 bytes.
- `VARBINARY(MAX)`: Variable-length binary data, up to 2^31-1 bytes (~2GB).

**5. Other Data Types**
- `UNIQUEIDENTIFIER`: 16-byte GUID (e.g., 6F9619FF-8B86-D011-B42D-00C04FC964FF).
- `XML`: Stores XML data, up to 2GB.
- `SQL_VARIANT`: Stores values of various SQL Server data types (except TEXT, NTEXT, IMAGE, and a few others).
- `CURSOR`: Reference to a cursor object (used in stored procedures).
- `TABLE`: Stores a result set for temporary processing (table variables or temp tables).
- `HIERARCHYID`: Represents a position in a hierarchy (e.g., for organizational charts).
- `GEOMETRY`: Planar spatial data (e.g., points, lines, polygons).
- `GEOGRAPHY`: Geodetic spatial data (e.g., GPS coordinates).


## [SQL Operators](https://learn.microsoft.com/en-us/sql/t-sql/language-elements/operators-transact-sql)
SQL operators are symbols or keywords used to perform operations on data in SQL queries.
- Perform operations like calculations, comparisons, and logical checks.
- Enable filtering, calculating, and updating data in databases.
- Essential for query optimization and accurate data management.  

Below is a concise overview of the main SQL Server operators, grouped by category:  

**1. Arithmetic Operators**: Used for mathematical calculations
- `+`: Addition (e.g., `5 + 3` = 8).
- `-`: Subtraction (e.g., `5 - 3` = 2).
- `*`: Multiplication (e.g., `5 * 3` = 15).
- `/`: Division (e.g., `6 / 2` = 3).
- `%`: Modulo (returns remainder, e.g., `7 % 2` = 1).

**2. Comparison Operators**: Used to compare values, typically in `WHERE` clauses
- `=`: Equal to (e.g., `column = 10`).
- `<>` or `!=`: Not equal to (e.g., `column <> 10`).
- `<`: Less than (e.g., `column < 10`).
- `>`: Greater than (e.g., `column > 10`).
- `<=`: Less than or equal to (e.g., `column <= 10`).
- `>=`: Greater than or equal to (e.g., `column >= 10`).
- `!<`: Not less than (equivalent to `>=`).
- `!>`: Not greater than (equivalent to `<=`).

**3. Logical Operators**: Combine multiple conditions in `WHERE` clauses
- `AND`: True if both conditions are true (e.g., `WHERE age > 18 AND age < 30`).
- `OR`: True if at least one condition is true (e.g., `WHERE age < 18 OR age > 65`).
- `NOT`: Negates a condition (e.g., `WHERE NOT age = 18`).
- `ALL`: True if all values in a subquery meet the condition (e.g., `WHERE column > ALL (subquery)`).
- `ANY` or `SOME`: True if any value in a subquery meets the condition (e.g., `WHERE column > ANY (subquery)`).
- `EXISTS`: True if a subquery returns at least one row (e.g., `WHERE EXISTS (subquery)`).
- `IN`: True if a value matches any value in a list or subquery (e.g., `WHERE column IN (1, 2, 3)`).
- `BETWEEN`: True if a value is within a range (inclusive, e.g., `WHERE age BETWEEN 18 AND 30`).

**4. Bitwise Operators**: Perform bit-level operations on integer types
- `&`: Bitwise AND (e.g., `5 & 3 = 1`).
- `|`: Bitwise OR (e.g., `5 | 3 = 7`).
- `^`: Bitwise XOR (e.g., `5 ^ 3 = 6`).
- `~`: Bitwise NOT (e.g., `~5` inverts bits).

**5. String Operators**: Used for string manipulation
- `+`: String concatenation (e.g., `'First' + ' ' + 'Last'` = 'First Last').
- `LIKE`: Pattern matching (e.g., `WHERE name LIKE '%son'` matches names ending with 'son').
- `%`: Wildcard for any sequence of characters in `LIKE` (e.g., `'A%'`).
- `_`: Wildcard for a single character in `LIKE` (e.g., `'A_'` matches 'AB', 'AC', etc.).
- `[]`: Wildcard for a range or set of characters in `LIKE` (e.g., `'[A-C]%'` matches names starting with A, B, or C).
- `[^]`: Wildcard for characters not in a range or set in `LIKE` (e.g., `'[^A-C]%'`).

**6. Set Operators**: Used to combine results from multiple `SELECT` statements
- `UNION`: Combines rows from two queries, removing duplicates.
- `UNION ALL`: Combines rows, keeping duplicates.
- `INTERSECT`: Returns rows common to both queries.
- `EXCEPT`: Returns rows in the first query but not in the second.


## Data Constraints
Data constraints are rules applied to table columns to enforce data integrity and consistency. They ensure that the data entered into the database adheres to specific criteria, preventing invalid or inconsistent data from being stored.  

Common types of data constraints include:

### Primary Key Constraint
Ensures that each row in a table is uniquely identifiable and does not contain duplicate or NULL values in the specified column(s).  
- Uniquely identifies each record.
- Automatically enforces uniqueness and non-nullability.
- Only one primary key per table (can include multiple columns for a composite key).
- Creates a clustered index by default if none exists.
```sql
-- CREATE TABLE --
CREATE TABLE Employees (
    EmployeeId INT PRIMARY KEY,
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL
);

-- ALTER TABLE --
ALTER TABLE Employees ALTER COLUMN EmployeeId INT NOT NULL;

ALTER TABLE Employees
ADD CONSTRAINT PK_Employees PRIMARY KEY (EmployeeId);
```

### Foreign Key Constraint
Enforces a relationship between two tables by ensuring that values in a column (or columns) in one table match values in the primary key or unique key of another table.
- Maintains referential integrity between related tables.
- Can allow NULL values (unless specified otherwise).
- Supports cascading actions (e.g., `ON DELETE CASCADE` or `ON UPDATE CASCADE`).
- Multiple foreign keys can exist in a table.
```sql
-- CREATE TABLE --
CREATE TABLE Departments (
    DepartmentId INT PRIMARY KEY,
    DepartmentName NVARCHAR(100) NOT NULL
);
CREATE TABLE Employees (
    EmployeeId INT PRIMARY KEY,
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL,
    DepartmentId INT CONSTRAINT FK_Employees_Departments FOREIGN KEY (DepartmentId) 
    REFERENCES Departments(DepartmentId)
    ON DELETE SET NULL
);

-- ALTER TABLE --
ALTER TABLE Employees
ADD CONSTRAINT FK_Employees_Departments FOREIGN KEY (DepartmentId)
REFERENCES Departments(DepartmentId)
ON DELETE SET NULL;
```

### Composite Key Constraint
A composite key is a primary key that consists of two or more columns. It ensures that the combination of values in these columns is unique across the table.
- Uniquely identifies records based on multiple columns.
- Useful when a single column is insufficient for uniqueness.
```sql
-- CREATE TABLE --
CREATE TABLE OrderItems (
    OrderId INT,
    ProductId INT,
    Quantity INT,
    PRIMARY KEY (OrderId, ProductId)
);

-- ALTER TABLE --
ALTER TABLE OrderItems
ADD CONSTRAINT PK_OrderItems PRIMARY KEY (OrderId, ProductId);
```

### Unique Constraint
Ensures all values in a column or set of columns are unique across all rows in the table.
- Unlike a primary key, a unique constraint allows NULL values (but only one NULL for a single-column unique constraint).
- Multiple unique constraints can exist in a table.
```sql
-- CREATE TABLE --
CREATE TABLE Employees (
    EmployeeId INT IDENTITY(1,1) PRIMARY KEY,
    Email NVARCHAR(100) UNIQUE,
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL
);

-- ALTER TABLE --
ALTER TABLE Employees
ADD CONSTRAINT UQ_Employees_Email UNIQUE (Email);
```

### Not Null Constraint
Prevents NULL values from being inserted into a column.
- Ensures a column must always have a valid value.
- Commonly used with primary keys (implicitly included) but can be applied to any column.
```sql
-- CREATE TABLE --
CREATE TABLE Employees (
    EmployeeId INT IDENTITY(1,1) PRIMARY KEY,
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL
);

-- ALTER TABLE --
ALTER TABLE Employees
ALTER COLUMN FirstName NVARCHAR(50) NOT NULL;
```

### Check Constraint
Ensures that all values in a column satisfy a specific condition defined by a Boolean expression.
- Can be applied to one or more columns.
- Used to enforce domain integrity (e.g., restricting values to a specific range).
```sql
-- CREATE TABLE --
CREATE TABLE Employees (
    EmployeeId INT IDENTITY(1,1) PRIMARY KEY,
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL,
    Age INT CHECK (Age >= 18 AND Age <= 65)
);

-- ALTER TABLE --
ALTER TABLE Employees
ADD CONSTRAINT CHK_Employees_Age CHECK (Age >= 18 AND Age <= 65);
```

### Default Constraint
Sets a default value for a column when no value is specified during an `INSERT` operation.
- Helps avoid NULL values when a value is not explicitly provided.
- Can be overridden by explicitly providing a value.
```sql
-- CREATE TABLE --
CREATE TABLE Employees (
    EmployeeId INT IDENTITY(1,1) PRIMARY KEY,
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL,
    HireDate DATETIME DEFAULT GETDATE(),
    IsActive BIT DEFAULT 1
);

-- ALTER TABLE --
ALTER TABLE Employees
ADD CONSTRAINT DF_Employees_HireDate DEFAULT GETDATE() FOR HireDate;
```
