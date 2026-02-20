CREATE DATABASE IoT_Monitoreo;
GO

USE IoT_Monitoreo;

CREATE TABLE sensores (
    id INT IDENTITY(1,1) PRIMARY KEY,
    temperatura FLOAT,
    humedad FLOAT,
    luz INT,
    vibracion BIT,
    llama BIT,
    fecha DATETIME DEFAULT GETDATE()
);