ifeq ($(strip $(LEADER_HRM_ENABLE)), yes)
	SRC += leader_hrm.c
	OPT_DEFS += -DLEADER_HRM_ENABLE
endif