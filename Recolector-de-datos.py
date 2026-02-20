import serial
import pyodbc

# ----- Serial -----
ser = serial.Serial('COM4', 9600, timeout=1)

# ----- SQL Server -----
conn = pyodbc.connect(
    "DRIVER={ODBC Driver 17 for SQL Server};"
    "SERVER=localhost\SQLDEV;"
    "DATABASE=IoT_Monitoreo;"
    "Trusted_Connection=yes;"
)

cursor = conn.cursor()

print("📡 Pipeline activo...")

while True:
    try:
        linea = ser.readline().decode().strip()

        if linea:
            datos = linea.split(",")

            if len(datos) == 5:
                temp = float(datos[0])
                hum = float(datos[1])
                luz = int(datos[2])
                vib = int(datos[3])
                llama = int(datos[4])

                cursor.execute("""
                    INSERT INTO sensores
                    (temperatura, humedad, luz, vibracion, llama)
                    VALUES (?, ?, ?, ?, ?)
                """, temp, hum, luz, vib, llama)

                conn.commit()

                print("✅ Insertado:", datos)

    except Exception as e:
        print("❌ Error:", e)