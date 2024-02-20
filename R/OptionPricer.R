#' Price a European Up and In Option
#'
#' @param nInt Number of intervals in the path
#' @param barrier Barrier level
#' @param strike Option strike price
#' @param spot Initial spot price of the underlying asset
#' @param vol Volatility of the underlying asset
#' @param r Risk-free interest rate
#' @param expiry Time to maturity in years
#' @param nReps Number of repetitions for the Monte Carlo simulation
#' @return Theoretical price of the option
#' @export
priceOption <- function(nInt, barrier, strike, spot, vol, r, expiry, nReps) {
  .Call('_BarrierOptionPrices_priceEuropeanOption', nInt, barrier, strike, spot, vol, r, expiry, nReps)
}