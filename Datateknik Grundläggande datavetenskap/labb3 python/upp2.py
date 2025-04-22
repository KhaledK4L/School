momssats = 0.25
pris_utan_moms =int( input('pris utan moms: ') )
moms = momssats * pris_utan_moms
print("moms: " + str(moms) )
print("pris inklusiv moms: " + str(moms + pris_utan_moms))