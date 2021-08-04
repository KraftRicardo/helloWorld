

// create RSPN
//    features
//       support NULL values
//       frequency for every value
//       support A->B optimization
//    create the base assemble
//       sub RSPN cover 1 or 2 tables
//       compute RDC values (to check when to cover a join table)
//    test with easy queries
//    safe model

// query (compilation) Hardcoded bench mark
//    Support this
//       AGG  = COUNT, SUM or AVG
//       OP = < > = <= >= IN
//       GROUP BY on one or several attributes
//    e.g. COUNT cases
//       (1) an RSPN exists that exactly matches the tables of the query
//       (2) the RSPN is larger and covers more tables (tuple factors)
//       (3) we need to combine multiple RSPNs since there is no single RSPN that contains all tables of
//       the query
//    execution strategy
//       at runtime we greedily use the RSPN that currently handles the filter predicates with the highest
//       sum of pairwise RDC values
//    AVG
//    SUM
//    GROUP BY

// extensions
//    ( confidence intervals (for AQP) )
//    support updates via
//       insert
//       delete
//       recursive update of the tree
//    ( base ensemble extensions )
//       RSPNs that cover more than two tables

// performance (cardinality)
//    read real data sets
//    generate synthetic data sets
//    training time & storage overhead
//    accuracy
//       q-error calc
//       generate table
//       something to create a statistics or to import to RStudio
//    testing code to run and measure
//       different cases, difficulty, data sets, query sets
//       measure latencies
