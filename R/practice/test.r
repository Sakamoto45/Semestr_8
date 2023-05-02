f <- function(tt, mm, dd, gg, tm, ..., mmd = 31, ddg = 18) {
    dots <- list(...)
    print(dots)
    print(c(mm, ddg, tm, dd, tt, dots[[2]], mmd, gg, dots[[1]]))
}
f(t = 42, m = 43, ddg = 5, tt = 8, td = 50, 3, 4, 7, 6, 13)



# 43 5  42 3 8 7 31 4 50

# tt = 8
# ddg = 5
# mmd = 31
# mm = m = 43
# tm = t = 42
# dd = 3
# gg = 4
# dots = td = 50, 7, 6, 13
