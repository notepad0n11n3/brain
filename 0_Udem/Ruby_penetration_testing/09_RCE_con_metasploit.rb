#!/usr/bin/env ruby

require 'drb'

class RShell
  def exec(cmd)
    "#{cmd}"
  end
end

DRb.start_service("druby://0.0.0.0:8080", RShell.new)
DRb.thread.join
