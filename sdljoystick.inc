
  //from "sdl_joystick.h"

  {**
   *  SDL_joystick.h
   *
   *  In order to use these functions, SDL_Init() must have been called
   *  with the ::SDL_INIT_JOYSTICK flag.  This causes SDL to scan the system
   *  for joysticks, and load appropriate drivers.
   *}

type

  {* The joystick structure used to identify an SDL joystick *}
  PSDL_Joystick = Pointer; // todo!!

{* A structure that encodes the stable unique id for a joystick device *}

  TSDL_JoystickGUID = record
    data: array[0..15] of UInt8;
  end;

  TSDL_JoystickID = SInt32;

  {* Function prototypes *}
  {**
   *  Count the number of joysticks attached to the system right now
   *}
function SDL_NumJoysticks: SInt32 cdecl; external {$IFDEF GPC} name 'SDL_NumJoysticks' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Get the implementation dependent name of a joystick.
   *  This can be called before any joysticks are opened.
   *  If no name can be found, this function returns NULL.
   *}
function SDL_JoystickNameForIndex(device_index: SInt32): PAnsiChar cdecl; external {$IFDEF GPC} name 'SDL_JoystickNameForIndex' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Open a joystick for use.
   *  The index passed as an argument refers tothe N'th joystick on the system.
   *  This index is the value which will identify this joystick in future joystick
   *  events.
   *
   *  A joystick identifier, or NULL if an error occurred.
   *}
function SDL_JoystickOpen(device_index: SInt32): PSDL_Joystick cdecl; external {$IFDEF GPC} name 'SDL_JoystickOpen' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Return the name for this currently opened joystick.
   *  If no name can be found, this function returns NULL.
   *}
function SDL_JoystickName(joystick: PSDL_Joystick): PAnsiChar cdecl; external {$IFDEF GPC} name 'SDL_JoystickName' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Return the GUID for the joystick at this index
   *}
function SDL_JoystickGetDeviceGUID(device_index: SInt32): TSDL_JoystickGUID cdecl; external {$IFDEF GPC} name 'SDL_JoystickGetDeviceGUID' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Return the GUID for this opened joystick
   *}
function SDL_JoystickGetGUID(joystick: PSDL_Joystick): TSDL_JoystickGUID cdecl; external {$IFDEF GPC} name 'SDL_JoystickGetGUID' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Return a string representation for this guid. pszGUID must point to at least 33 bytes
   *  (32 for the string plus a NULL terminator).
   *}
procedure SDL_JoystickGetGUIDString(guid: TSDL_JoystickGUId; pszGUID: PAnsiChar; cbGUID: SInt32) cdecl; external {$IFDEF GPC} name 'SDL_JoystickGetGUIDString' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  convert a string into a joystick formatted guid
   *}
function SDL_JoystickGetGUIDFromString(const pchGUID: PAnsiChar): TSDL_JoystickGUID cdecl; external {$IFDEF GPC} name 'SDL_JoystickGetGUIDFromString' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Returns SDL_TRUE if the joystick has been opened and currently connected, or SDL_FALSE if it has not.
   *}
function SDL_JoystickGetAttached(joystick: PSDL_Joystick): TSDL_Bool cdecl; external {$IFDEF GPC} name 'SDL_JoystickGetAttached' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Get the instance ID of an opened joystick or -1 if the joystick is invalid.
   *}
function SDL_JoystickInstanceID(joystick: PSDL_Joystick): TSDL_JoystickID cdecl; external {$IFDEF GPC} name 'SDL_JoystickInstanceID' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Get the number of general axis controls on a joystick.
   *}
function SDL_JoystickNumAxes(joystick: PSDL_Joystick): SInt32 cdecl; external {$IFDEF GPC} name 'SDL_JoystickNumAxes' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Get the number of trackballs on a joystick.
   *
   *  Joystick trackballs have only relative motion events associated
   *  with them and their state cannot be polled.
   *}
function SDL_JoystickNumBalls(joystick: PSDL_Joystick): SInt32 cdecl; external {$IFDEF GPC} name 'SDL_JoystickNumBalls' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Get the number of POV hats on a joystick.
   *}
function SDL_JoystickNumHats(joystick: PSDL_Joystick): SInt32 cdecl; external {$IFDEF GPC} name 'SDL_JoystickNumHats' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Get the number of buttons on a joystick.
   *}
function SDL_JoystickNumButtons(joystick: PSDL_Joystick): SInt32 cdecl; external {$IFDEF GPC} name 'SDL_JoystickNumButtons' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Update the current state of the open joysticks.
   *
   *  This is called automatically by the event loop if any joystick
   *  events are enabled.
   *}
procedure SDL_JoystickUpdate cdecl; external {$IFDEF GPC} name 'SDL_JoystickUpdate' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Enable/disable joystick event polling.
   *
   *  If joystick events are disabled, you must call SDL_JoystickUpdate()
   *  yourself and check the state of the joystick when you want joystick
   *  information.
   *
   *  The state can be one of ::SDL_QUERY, ::SDL_ENABLE or ::SDL_IGNORE.
   *}
function SDL_JoystickEventState(state: SInt32): SInt32 cdecl; external {$IFDEF GPC} name 'SDL_JoystickEventState' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Get the current state of an axis control on a joystick.
   *
   *  The state is a value ranging from -32768 to 32767.
   *
   *  The axis indices start at index 0.
   *}
function SDL_JoystickGetAxis(joystick: PSDL_Joystick; axis: SInt32): SInt16 cdecl; external {$IFDEF GPC} name 'SDL_JoystickGetAxis' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Hat positions
   *}
const
  SDL_HAT_CENTERED  = $00;
  SDL_HAT_UP        = $01;
  SDL_HAT_RIGHT     = $02;
  SDL_HAT_DOWN      = $04;
  SDL_HAT_LEFT      = $08;
  SDL_HAT_RIGHTUP   = SDL_HAT_RIGHT or SDL_HAT_UP;
  SDL_HAT_RIGHTDOWN = SDL_HAT_RIGHT or SDL_HAT_DOWN;
  SDL_HAT_LEFTUP    = SDL_HAT_LEFT or SDL_HAT_UP;
  SDL_HAT_LEFTDOWN  = SDL_HAT_LEFT or SDL_HAT_DOWN;

  {**
   *  Get the current state of a POV hat on a joystick.
   *
   *  The hat indices start at index 0.
   *
   *  The return value is one of the following positions:
   *   - SDL_HAT_CENTERED
   *   - SDL_HAT_UP
   *   - SDL_HAT_RIGHT
   *   - SDL_HAT_DOWN
   *   - SDL_HAT_LEFT
   *   - SDL_HAT_RIGHTUP
   *   - SDL_HAT_RIGHTDOWN
   *   - SDL_HAT_LEFTUP
   *   - SDL_HAT_LEFTDOWN
   *}
function SDL_JoystickGetHat(joystick: PSDL_Joystick; hat: SInt32): UInt8 cdecl; external {$IFDEF GPC} name 'SDL_JoystickGetHat' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Get the ball axis change since the last poll.
   *
   *  0, or -1 if you passed it invalid parameters.
   *
   *  The ball indices start at index 0.
   *}
function SDL_JoystickGetBall(joystick: PSDL_Joystick; ball: SInt32; dx: PInt; dy: PInt): SInt32 cdecl; external {$IFDEF GPC} name 'SDL_JoystickGetBall' {$ELSE} SDL_LibName {$ENDIF};

  {**
   *  Get the current state of a button on a joystick.
   *
   *  The button indices start at index 0.
   *}
function SDL_JoystickGetButton(joystick: PSDL_Joystick; button: SInt32): UInt8 cdecl; external {$IFDEF GPC} name 'SDL_JoystickGetButton' {$ELSE} SDL_LibName {$ENDIF};
  {**
   *  Close a joystick previously opened with SDL_JoystickOpen().
   *}
procedure SDL_JoystickClose(joystick: PSDL_Joystick) cdecl; external {$IFDEF GPC} name 'SDL_JoystickClose' {$ELSE} SDL_LibName {$ENDIF};