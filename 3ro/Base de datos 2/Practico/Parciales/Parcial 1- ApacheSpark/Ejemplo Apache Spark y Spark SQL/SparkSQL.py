from pyspark import SparkConf, SparkContext
from pyspark.sql import SQLContext, Row
import collections

conf = SparkConf().setMaster("local").setAppName("CovidRegister")
sc = SparkContext(conf = conf)

lines = sc.textFile("file:///cursospark/Covid19Casos-100000.csv")
provincias = lines.map(lambda x: x.split(',')[5])
count = provincias.map(lambda w: (w, 1)).reduceByKey(lambda a, b: a + b)

provinciasColumns = count.map(lambda p: Row(Province = p[0], Registers = int(p[1])))

sqlContext = SQLContext(sc)
covidLog = sqlContext.createDataFrame(provinciasColumns)
covidLog.registerTempTable("Registros")

query = sqlContext.sql("SELECT Province, Registers FROM Registros order by Registers DESC LIMIT 5")
for data in query.collect():
    print ("|Nombre provincia: "+str(data.Province)+"          |Cantidad registrada: "+str(data.Registers)) 
