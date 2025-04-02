program triangular_matrix
    use, intrinsic :: iso_fortran_env, only : error_unit, DP => REAL64
    implicit none
    integer :: rows, cols, i, j, unit_nr, istat
    character(len=1024) :: file_name, msg
    real(kind=DP) :: r

    call get_arguments(file_name, rows, cols)
    open (newunit=unit_nr, file=file_name, form='unformatted', &
          access='stream', action='write', status='new', iostat=istat, &
          iomsg=msg)
    if (istat /= 0) then
        write (unit=error_unit, fmt='(2A)') 'error: ', trim(msg)
        stop 3
    end if
    r = 1.0_DP
    do i = 1, rows
        do j = i, cols
            write (unit=unit_nr, iostat=istat, iomsg=msg) r
            if (istat /= 0) then
                write (unit=error_unit, fmt='(2A)') 'error: ', trim(msg)
            end if
            r = r + 1.0_DP
        end do
    end do
    close(unit=unit_nr)

contains

    subroutine get_arguments(file_name, rows, cols)
        implicit none
        character(len=*), intent(out) :: file_name
        integer, intent(out) :: rows, cols
        character(len=128) :: buffer, msg
        integer :: istat

        if (command_argument_count() /= 3) then
            write (unit=error_unit, fmt='(A)') &
                'error: expecting file name and number of rows and columns as arguments'
            stop 1
        end if

        call get_command_argument(1, file_name)
        call get_command_argument(2, buffer)
        read (buffer, fmt=*, iomsg=msg, iostat=istat) rows
        if (istat /= 0) then
            write (unit=error_unit, fmt='(2A)') 'error: ', trim(msg)
            stop 2
        end if
        call get_command_argument(3, buffer)
        read (buffer, fmt=*, iomsg=msg, iostat=istat) cols
        if (istat /= 0) then
            write (unit=error_unit, fmt='(2A)') 'error: ', trim(msg)
            stop 2
        end if
    end subroutine get_arguments

end program triangular_matrix
