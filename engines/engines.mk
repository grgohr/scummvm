ifdef ENABLE_SCUMM
DEFINES += -DENABLE_SCUMM=$(ENABLE_SCUMM)
MODULES += engines/scumm

ifdef ENABLE_SCUMM_7_8
DEFINES += -DENABLE_SCUMM_7_8
endif

ifdef ENABLE_HE
DEFINES += -DENABLE_HE
endif

endif

ifdef ENABLE_AGI
DEFINES += -DENABLE_AGI=$(ENABLE_AGI)
MODULES += engines/agi
endif

ifdef ENABLE_AGOS
DEFINES += -DENABLE_AGOS=$(ENABLE_AGOS)
MODULES += engines/agos

ifdef ENABLE_AGOS2
DEFINES += -DENABLE_AGOS2
endif
endif

ifdef ENABLE_AVALANCHE
DEFINES += -DENABLE_AVALANCHE=$(ENABLE_AVALANCHE)
MODULES += engines/avalanche
endif

ifdef ENABLE_CGE
DEFINES += -DENABLE_CGE=$(ENABLE_CGE)
MODULES += engines/cge
endif

ifdef ENABLE_CINE
DEFINES += -DENABLE_CINE=$(ENABLE_CINE)
MODULES += engines/cine
endif

ifdef ENABLE_COMPOSER
DEFINES += -DENABLE_COMPOSER=$(ENABLE_COMPOSER)
MODULES += engines/composer
endif

ifdef ENABLE_CRUISE
DEFINES += -DENABLE_CRUISE=$(ENABLE_CRUISE)
MODULES += engines/cruise
endif

ifdef ENABLE_DRACI
DEFINES += -DENABLE_DRACI=$(ENABLE_DRACI)
MODULES += engines/draci
endif

ifdef ENABLE_DRASCULA
DEFINES += -DENABLE_DRASCULA=$(ENABLE_DRASCULA)
MODULES += engines/drascula
endif

ifdef ENABLE_DREAMWEB
DEFINES += -DENABLE_DREAMWEB=$(ENABLE_DREAMWEB)
MODULES += engines/dreamweb
endif

ifdef ENABLE_FULLPIPE
DEFINES += -DENABLE_FULLPIPE=$(ENABLE_FULLPIPE)
MODULES += engines/fullpipe
endif

ifdef ENABLE_GOB
DEFINES += -DENABLE_GOB=$(ENABLE_GOB)
MODULES += engines/gob
endif

ifdef ENABLE_GROOVIE
DEFINES += -DENABLE_GROOVIE=$(ENABLE_GROOVIE)
MODULES += engines/groovie

ifdef ENABLE_GROOVIE2
DEFINES += -DENABLE_GROOVIE2
endif
endif

ifdef ENABLE_HOPKINS
DEFINES += -DENABLE_HOPKINS=$(ENABLE_HOPKINS)
MODULES += engines/hopkins
endif

ifdef ENABLE_HUGO
DEFINES += -DENABLE_HUGO=$(ENABLE_HUGO)
MODULES += engines/hugo
endif

ifdef ENABLE_KYRA
DEFINES += -DENABLE_KYRA=$(ENABLE_KYRA)
MODULES += engines/kyra

ifdef ENABLE_LOL
DEFINES += -DENABLE_LOL
endif

ifdef ENABLE_EOB
DEFINES += -DENABLE_EOB
endif
endif

ifdef ENABLE_LASTEXPRESS
DEFINES += -DENABLE_LASTEXPRESS=$(ENABLE_LASTEXPRESS)
MODULES += engines/lastexpress
endif

ifdef ENABLE_LURE
DEFINES += -DENABLE_LURE=$(ENABLE_LURE)
MODULES += engines/lure
endif

ifdef ENABLE_MADE
DEFINES += -DENABLE_MADE=$(ENABLE_MADE)
MODULES += engines/made
endif

ifdef ENABLE_MOHAWK
DEFINES += -DENABLE_MOHAWK=$(ENABLE_MOHAWK)
MODULES += engines/mohawk

ifdef ENABLE_CSTIME
DEFINES += -DENABLE_CSTIME
endif

ifdef ENABLE_MYST
DEFINES += -DENABLE_MYST
endif

ifdef ENABLE_RIVEN
DEFINES += -DENABLE_RIVEN
endif
endif

ifdef ENABLE_MORTEVIELLE
DEFINES += -DENABLE_MORTEVIELLE=$(ENABLE_MORTEVIELLE)
MODULES += engines/mortevielle
endif

ifdef ENABLE_NEVERHOOD
DEFINES += -DENABLE_NEVERHOOD=$(ENABLE_NEVERHOOD)
MODULES += engines/neverhood
endif

ifdef ENABLE_PARALLACTION
DEFINES += -DENABLE_PARALLACTION=$(ENABLE_PARALLACTION)
MODULES += engines/parallaction
endif

ifdef ENABLE_PEGASUS
DEFINES += -DENABLE_PEGASUS=$(ENABLE_PEGASUS)
MODULES += engines/pegasus
endif

ifdef ENABLE_QUEEN
DEFINES += -DENABLE_QUEEN=$(ENABLE_QUEEN)
MODULES += engines/queen
endif

ifdef ENABLE_SAGA
DEFINES += -DENABLE_SAGA=$(ENABLE_SAGA)
MODULES += engines/saga

ifdef ENABLE_IHNM
DEFINES += -DENABLE_IHNM
endif

ifdef ENABLE_SAGA2
DEFINES += -DENABLE_SAGA2
endif
endif

ifdef ENABLE_SCI
DEFINES += -DENABLE_SCI=$(ENABLE_SCI)
MODULES += engines/sci

ifdef ENABLE_SCI32
DEFINES += -DENABLE_SCI32
endif
endif

ifdef ENABLE_SKY
DEFINES += -DENABLE_SKY=$(ENABLE_SKY)
MODULES += engines/sky
endif

ifdef ENABLE_SWORD1
DEFINES += -DENABLE_SWORD1=$(ENABLE_SWORD1)
MODULES += engines/sword1
endif

ifdef ENABLE_SWORD2
DEFINES += -DENABLE_SWORD2=$(ENABLE_SWORD2)
MODULES += engines/sword2
endif

ifdef ENABLE_SWORD25
DEFINES += -DENABLE_SWORD25=$(ENABLE_SWORD25)
MODULES += engines/sword25
endif

ifdef ENABLE_TESTBED
DEFINES += -DENABLE_TESTBED=$(ENABLE_TESTBED)
MODULES += engines/testbed
endif

ifdef ENABLE_TEENAGENT
DEFINES += -DENABLE_TEENAGENT=$(ENABLE_TEENAGENT)
MODULES += engines/teenagent
endif

ifdef ENABLE_TINSEL
DEFINES += -DENABLE_TINSEL=$(ENABLE_TINSEL)
MODULES += engines/tinsel
endif

ifdef ENABLE_TOLTECS
DEFINES += -DENABLE_TOLTECS=$(ENABLE_TOLTECS)
MODULES += engines/toltecs
endif

ifdef ENABLE_TONY
DEFINES += -DENABLE_TONY=$(ENABLE_TONY)
MODULES += engines/tony
endif

ifdef ENABLE_TOON
DEFINES += -DENABLE_TOON=$(ENABLE_TOON)
MODULES += engines/toon
endif

ifdef ENABLE_TOUCHE
DEFINES += -DENABLE_TOUCHE=$(ENABLE_TOUCHE)
MODULES += engines/touche
endif

ifdef ENABLE_TSAGE
DEFINES += -DENABLE_TSAGE=$(ENABLE_TSAGE)
MODULES += engines/tsage
endif

ifdef ENABLE_TUCKER
DEFINES += -DENABLE_TUCKER=$(ENABLE_TUCKER)
MODULES += engines/tucker
endif

ifdef ENABLE_WINTERMUTE
DEFINES += -DENABLE_WINTERMUTE=$(ENABLE_WINTERMUTE)
MODULES += engines/wintermute
endif

ifdef ENABLE_ZVISION
DEFINES += -DENABLE_ZVISION=$(ENABLE_ZVISION)
MODULES += engines/zvision
endif

ifdef ENABLE_VOYEUR
DEFINES += -DENABLE_VOYEUR=$(ENABLE_VOYEUR)
MODULES += engines/voyeur
endif
