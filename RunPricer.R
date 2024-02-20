devtools::install_local("~/Desktop/Advanced R/Advanced Visualisation in R/BarrierOptionPrices")
library(BarrierOptionPrices)

result <- priceOption(nInt = 100, barrier = 160, strike = 150, spot = 140, vol = 0.24, r = 0.07, expiry = 0.75, nReps = 100)

result

