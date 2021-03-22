MIT License

IoTLamp
#IoT
#Arduino
#WeMosD1

![IoTLamp](https://github.com/sh-navid/IoTLamp/blob/master/IoTLampFigures/IoTLamp.jpg?raw=true)

لینک ویدیو

https://www.linkedin.com/posts/activity-6779465985301745664-uIZu
_____
از شماتیک و مدارها 100% مطمئن نیستم چون تخصص من نیست. پس مسئولیت استفاده با خودتون

:)

_____
برای شبیه سازی از

https://falstad.com/circuit/

استفاده کردم. معمولا خوب شبیه سازی میکنه و خیلی به کمکم اومده

کد شبیه سازی با فالستاد و همینطور تصویر خروجی رو ضمیمه کردم

![Simulation](https://github.com/sh-navid/IoTLamp/blob/master/IoTLampFigures/Simulation.png?raw=true)

_____
برای شماتیک از نرم افزار فریتزینگ استفاده کردم

https://fritzing.org/

و همینطور از ترانزیستور

BC547 

استفاده کردم که از نوع

NPN

هست


دلیل استفاده از ترانزیستور این هست که خود میکرویی که استفاده کردم ولتاژ 3.3 با شدت جریان خیلی کم تولید میکنه که برای راه اندازی یک قطعه دیگه ممکنه مناسب نباشه. مسیر یو اس بی نیاز به ولتاژ 5 ولتی و شدت جریان بیشتر داره

![Schematic](https://github.com/sh-navid/IoTLamp/blob/master/IoTLampFigures/Schematic.png?raw=true)

تو شماتیک منظورم از سیگنال، خروجی

GPIO

میکرو هست که میتونه هر چیزی باشه از جمله

Arduino

FPGA

RaspberryPi

ESP8266

و هر نوع پردازنده و میکروی دیگه ای

_____
یک مثال هم روی برد-برد زدم که چون ترانزیستور

BC547

تموم شده بود با

BC548

تست گرفتم

فکر میکنم با هر ترانزیستور

NPNی

بشه انجام داد اما چون رشته تحصیلیم الکترونیک نیست با اطمینان نمیتونم بگم