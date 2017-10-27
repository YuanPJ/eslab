from gattlib import GATTRequester, GATTResponse

request = GATTRequester("B8:27:EB:50:FE:72")

data = request.read_by_handle(0x000c)

d =  data[0].encode('hex')
temp, humid = map(lambda x: int(x, 16), (d[0:2], d[2:]))
print 'Temperature =', temp
print 'Humidity =', humid

