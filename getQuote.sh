#!/bin/bash
cat data/indices.txt | while read y

do
curl -s "https://query1.finance.yahoo.com/v7/finance/quote?symbols=$y.to" > ./data/$y.json

done

