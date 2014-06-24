package.cpath = package.cpath .. ";./lib/?.so"
local taglib = require "taglib"

--[[
  This file shows what TagLib functions are supported by lua-taglib
  and how to use them.
  ]]--

success = taglib.file('music.mp3')
if success then

    -- tags
    tags = taglib.tag()
    print("Artist: " .. tags.artist)
    print("Album: " .. tags.album)
    print("Title: " .. tags.title)
    print("Genre: " .. tags.genre)
    print("Track: " .. tags.track)
    print("Year: " .. tags.year)
    print("Comment: " .. tags.comment)

    -- audio values
    print("Length: " .. taglib.length())
    print("Bitrate: " .. taglib.bitrate())
    print("Sample Rate: " .. taglib.sampleRate())
    print("Channels: " .. taglib.channels())
end
