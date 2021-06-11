ENCODER_ENABLE = yes       # Enable the use of one or more encoders
SPLIT_TRANSPORT = mirror   # Allow to have information sent on both sides
TAP_DANCE_ENABLE = yes     # Activate tap dance
COMBO_ENABLE = yes 				 # Enable combos
NKRO_ENABLE = yes 				 # Enable NKRO: any number of key-presses at once
LTO_ENABLE = yes  				 # Enable Link Time Optimization
MOUSEKEY_ENABLE = yes      # Enable mouse keys
EXTRAKEY_ENABLE = yes			 # Enable media keys

EXTRFLAGS += -flto
