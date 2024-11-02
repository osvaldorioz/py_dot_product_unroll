
from fastapi import FastAPI
import dot_product_unroll
from pydantic import BaseModel
from typing import List
import time
import json

app = FastAPI()

# Definir el modelo para el vector
class Vector(BaseModel):
    vector: List[float]


@app.get("/")
async def root():
    return {"message": "Dot product unroll"}

@app.post("/dotproductunroll")
async def kd(a: Vector, b: Vector):
    start = time.time()
    
    result = dot_product_unroll.dot_product(a.vector, b.vector)

    end = time.time()

    var1 = end - start

    j1 = {
        "Time taken in seconds": var1,
        "Vector a": a.vector,
        "Vector b": b.vector,
        "Dot product result": result
    }
    jj = json.dumps(j1)

    return jj