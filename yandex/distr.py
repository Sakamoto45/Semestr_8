from scipy.stats import t, chi2
[print(str(i) + " : " + str(t.ppf(0.975, i-1)) + ",")
 for i in range(5, 21)]
[print(str(i) + " : " + str(chi2.ppf(0.025, i-1)) + ",")
 for i in range(5, 21)]
[print(str(i) + " : " + str(chi2.ppf(0.975, i-1)) + ",")
 for i in range(5, 21)]


[print(str(i) + " : " + str(chi2.ppf(0.95, i-1)) + ",")
 for i in range(5, 21)]
