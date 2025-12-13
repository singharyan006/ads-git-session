import os
from dotenv import load_dotenv
from neo4j import GraphDatabase

load_dotenv()  # loads .env into environment variables

NEO4J_URI = os.getenv("NEO4J_URI")
NEO4J_USER = os.getenv("NEO4J_USER")
NEO4J_PASSWORD = os.getenv("NEO4J_PASSWORD")

driver = GraphDatabase.driver(
  NEO4J_URI,      
  auth=(NEO4J_USER, NEO4J_PASSWORD),
)
driver.verify_connectivity()

cypher1="""
MERGE (p:Person{name:$name,credit:$credit,debit:$debit,email:$email})
"""



params1={
  "name":"Prachi",
  "credit":"200",
  "debit":"100",
  "email":"prachi@gmail.com"
}

params2={
  "name":"Prisha",
  "credit":"300",
  "debit":"100",
  "email":"prisha@gmail.com"
}


records, summary, keys = driver.execute_query(cypher1,params1)
records, summary, keys = driver.execute_query(cypher1,params2)

params1_net=int(params1["credit"])-int(params1["debit"])
params2_net=int(params2["credit"])-int(params2["debit"])

if params1_net > params2_net:
  amount = params1_net - params2_net
  from_=params2['email']
  to_=params1['email']
elif params2_net > params1_net:
  amount = params2_net - params1_net
  from_=params1['email']
  to_=params2['email']
else:
  amount = 0
  from_=None
  to_=None


if amount>0:
  cypher="""
  MATCH (p:Person{email:$from})
  MATCH(q:Person{email:$to})
  MERGE (p)-[t:TRANSACTION]->(q)
  SET t.amount = $amount
  """
  params={
    "from":from_,
    "to":to_,
    "amount":amount
  }
  print(params)
  records, summary, keys = driver.execute_query(cypher,params)


